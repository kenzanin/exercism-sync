unit Satellite;

{$mode ObjFPC}{$H+}

interface

type
  TStrArray = Array of String;

  PNode = ^TNode;

  TNode = record
    Data  : string;
    Left  : PNode;
    Right : PNode;
  end;

function treeFromTraversals(const preorder, inorder : TStrArray) : PNode;

implementation

uses SysUtils, Classes;

function treeFromTraversals(const preorder, inorder : TStrArray) : PNode;
var
  j, rootIdx, n: integer;
  seen, thisInorder: TStringList;
  function ArrToSet(const arr: TStrArray): TStringList;
  var
    k: integer;
    s: TStringList;
  begin
    s := TStringList.Create;
    s.Sorted := True;
    s.Duplicates := dupError;
    for k := 0 to High(arr) do
      s.Add(arr[k]);
    Result := s;
  end;
  function Build(preL, preR, inL, inR: integer): PNode;
  var
    rootVal: string;
    idx, leftLen, j: integer;
  begin
    if preL > preR then
      Exit(nil);
    New(Result);
    rootVal := preorder[preL];
    Result^.Data := rootVal;
    // Find root in inorder
    idx := -1;
    for j := inL to inR do
      if inorder[j] = rootVal then
      begin
        idx := j;
        break;
      end;
    if idx = -1 then
      raise Exception.Create('traversals must have the same elements');
    leftLen := idx - inL;
    Result^.Left := Build(preL + 1, preL + leftLen, inL, idx - 1);
    Result^.Right := Build(preL + leftLen + 1, preR, idx + 1, inR);
  end;
begin
  n := Length(preorder);
  if n <> Length(inorder) then
    raise Exception.Create('traversals must have the same length');
  // Check for unique items
  try
    seen := ArrToSet(preorder);
    try
      if seen.Count <> n then
        raise Exception.Create('traversals must contain unique items');
      // Check both traversals have same elements
      thisInorder := ArrToSet(inorder);
      try
        if seen.Count <> thisInorder.Count then
          raise Exception.Create('traversals must have the same elements');
        for j := 0 to seen.Count - 1 do
          if seen.Strings[j] <> thisInorder.Strings[j] then
          begin
            raise Exception.Create('traversals must have the same elements');
          end;
      finally
        thisInorder.Free;
      end;
    finally
      seen.Free;
    end;
  except
    on E: EStringListError do
      raise Exception.Create('traversals must contain unique items');
  end;
  if n = 0 then
    Exit(nil);
  Result := Build(0, n - 1, 0, n - 1);
end;

end.
