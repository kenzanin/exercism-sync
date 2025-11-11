local gigasecond = {}

function gigasecond.anniversary(any_date)
    any_date = any_date + 1e9
    return os.date("%x", any_date)
end

return gigasecond
