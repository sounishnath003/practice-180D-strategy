package Go

import (
	"strings"
)

func solveFunc(path string) string {
	parts := strings.Split(path, "/")
	var result []string
	for _, part := range parts {
		switch part {
		case "..":
			result = result[:len(result)-1]
		case ".":
		default:
			result = append(result, part)
		}
	}
	return strings.Join(result, "/")
}