local School = {}

function School:roster()
  return self.student
end

function School:add(name, class)
  if self.student[class] == nil then
    self.student[class] = {
      name
    }
  else
    table.insert(self.student[class], name)
    table.sort(self.student[class])
  end
end

function School:grade(index)
  if self.student[index] == nil then
    return {}
  end
  return self.student[index]
end

function School:new()
  local student = {}
  local n = {
    roster = School.roster,
    add = School.add,
    student = student,
    grade = School.grade
  }
  setmetatable(n, School)
  return n
end

return School
