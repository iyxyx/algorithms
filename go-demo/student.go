package main

import "fmt"

//结构体
type Student struct{
		id int
		name string
		c_score float64
	} // 未初始化int类型默认为0
func main()  {
	//结构体数组
	stuents:=[]Student{
	{101,"张三",80},
	{102,"李四",88},
	{103,"王五",70},
	{104,"赵六",90},
	}
	// 求最低分
	min:=stuents[0].c_score
	for i:=0;i<len(stuents);i++{
		if stuents[i].c_score<min{
			min=stuents[i].c_score
		}
	}
	fmt.Println("最低分:",min)
}
// 运行结果:最低分: 70