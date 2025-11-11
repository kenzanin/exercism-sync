package linkedlist

import "errors"

// Define List and Node types here.
// Note: The tests expect Node type to include an exported field with name Value to pass.
type List struct {
	begin *Node
	end   *Node
}
type Node struct {
	next  *Node
	prev  *Node
	Value interface{}
}

func NewList(args ...interface{}) *List {
	result := &List{}
	for _, v := range args {
		result.Push(v)
	}
	return result
}

func (n *Node) Next() *Node {
	return n.next
}

func (n *Node) Prev() *Node {
	return n.prev
}

func (l *List) Unshift(v interface{}) {
	new := Node{Value: v}
	if l.begin == nil {
		l.begin = &new
		l.end = &new
		return
	}
	l.begin.prev = &new
	new.next = l.begin
	l.begin = &new
}

func (l *List) Push(v interface{}) {
	new := Node{Value: v}

	if l.end == nil {
		l.begin = &new
		l.end = &new
		return
	}
	new.prev = l.end
	l.end.next = &new
	l.end = &new
}

func (l *List) Shift() (interface{}, error) {
	if l.begin == nil {
		return nil, errors.New("")
	}
	if l.begin == l.end {
		v := l.begin.Value
		l.begin, l.end = nil, nil
		return v, nil
	}

	n := l.begin

	l.begin = n.next
	n.next = nil
	l.begin.prev = nil
	return n.Value, nil
}

func (l *List) Pop() (interface{}, error) {
	if l.end == nil {
		return nil, errors.New("")
	}
	if l.begin == l.end {
		v := l.end.Value
		l.begin, l.end = nil, nil
		return v, nil
	}
	new := l.end

	l.end = new.prev
	new.prev = nil
	l.end.next = nil
	return new.Value, nil
}

func (l *List) Reverse() {
	if l.end == nil {
		return
	}
	l.begin, l.end = l.end, l.begin
	new := l.begin
	for new != nil {
		new.prev, new.next = new.next, new.prev
		new = new.next
	}
}

func (l *List) First() *Node {
	return l.begin
}

func (l *List) Last() *Node {
	return l.end
}
