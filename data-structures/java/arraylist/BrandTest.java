import java.util.ArrayList;

public class BrandTest {
    public static void main(String[] args) {
        // 1.创建ArrayList集合(存储Brand对象)
        ArrayList<Brand> brandList= new ArrayList<>();
        System.out.println("===1.初始集合===");
        System.out.println("集合是否为空："+brandList.isEmpty());
        System.out.println("集合元素个数："+brandList.size()+"\n");

        // 2.新增元素（末尾添加+指定索引插入）
        Brand huawei=new Brand ("华为","华为技术有限公司",1,"国际科技龙头",1);
        brandList.add(huawei);
        Brand apple=new Brand("苹果","苹果公司",2,"全球高端品牌",1);
        brandList.add(apple);
        brandList.add(1,new Brand("小米","小米科技",3,"性价比代表",1));
        System.out.println("===2.新增元素后===");
        printList(brandList); // 调用自定义打印方法

        // 3.查询操作（索引查询）
        System.out.println("\n===3.查询操作===");
        Brand firstBrand=brandList.get(0);
        System.out.println("索引0的元素:"+firstBrand.getBrandName());

        // 4.修改操作（替换指定索引元素）
        System.out.println("\n===4.修改操作===");
        Brand oppo=new Brand("OPPO","OPPO公司",4,"年轻人手机品牌",1);
        brandList.set(2,oppo);
        printList(brandList);

        // 5.删除操作（按索引删除+按对象删除）
        System.out.println("\n===5.删除操作===");
        brandList.remove(1); // 按索引删除
        brandList.remove(oppo); // 按对象删除
        printList(brandList);

        // 6.遍历操作
        System.out.println("\n===6.遍历操作===");
        for (int i=0;i<brandList.size();i++) {
            Brand b=brandList.get(i);
            System.out.println(b);
        }
    }
    
    // 自定义打印方法
    private static void printList(ArrayList<Brand> list) {
        for (int i=0;i<list.size();i++) {
            System.out.println(list.get(i));
        }
    }
}
