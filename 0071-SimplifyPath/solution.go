func simplifyPath(path string) string {
    if path == "" {
        return ""
    }
    items := strings.Split(path, "/")
    stack := make([]string, 0)
    for _, item := range items {
        switch item {
            case ".":
            case "":
            case "..":
                if (len(stack) != 0) {
                    stack = stack[:len(stack)-1]
                }
            default:
                stack = append(stack, "/" + item)
        }
    }

    ret := strings.Join(stack, "")
    if (ret == "") {
        ret = "/"
    }

    return ret;
}