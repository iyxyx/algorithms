public class Brand {
    private String brandName;
    private String companyName;
    private int id;
    private String description;
    private int status;

// 构造函数-有参构造
public Brand(String brandName, String companyName, int id, String description, int status) {
    this.brandName = brandName;
    this.companyName = companyName;
    this.id = id;
    this.description = description;
    this.status = status;
}

// get 和 set 方法
public String getBrandName() {
    return brandName;
}
public void setBrandName(String brandName) {
    this.brandName = brandName;
}

public String getCompanyName() {
    return companyName;
}

public void setCompanyName(String companyName) {
    this.companyName = companyName;
}

public int getId() {
    return id;
}
public void setId(int id) {
    this.id = id;
}
 
public String getDescription() {
    return description;
} 
public void setDescription(String description) {
    this.description = description;
}

public int getStatus() {
    return status;
}
public void setStatus(int status) {
    this.status = status;
}


//重写toString方法
@Override
public String toString() {
    String statusDesc = (status == 1) ? "启用" : "禁用";
    return String.format("Brand [brandName='%s', companyName='%s', id='%d', description='%s', status='%s']",
     brandName, companyName, id, description, statusDesc);
}
}
