# LibraryManagement

## 1 Yêu cầu kĩ thuật 
- Chương trình được thể hiện dưới dạng menu để người dùng chọn và thực hiện chức năng 
- Chỉ sử dụng các kiểu dữ liệu cơ bản và mảng 1 chiều 
- Không cần lưu trữ dữ liệu xuống tập tin 
- Không được sử dụng struct 
- Mã nguồn chương trình phải được tổ chức thành các file, các hàm phù hợp 
- Trước mỗi hàm, đều phải có comment rõ ràng cho biết hàm đó thực hiện chức năng gì, mô 
tả các tham số truyền vào, ý nghĩa giá trị trả về 
## 2 Đề bài 
Viết một chương trình C quản lí thư viện trên nền console:
Thư viện cần quản lí 3 loại thông tin gồm độc giả, sách và các phiếu mượn/trả sách. 
- Thông tin thẻ độc giả cần quản lí bao gồm: mã độc giả, họ tên, CMND, ngày tháng 
năm sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn của thẻ (48 tháng 
kể từ ngày lập thẻ). 
- Thông tin sách cần quản lí bao gồm: ISBN (mã sách), tên sách, tác giả, nhà xuất 
bản, năm xuất bản, thể loại, giá sách, số quyển sách. 
- Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự 
kiến, ngày trả thực tế và danh sách ISBN của các sách được mượn. Mỗi sách được 
mượn tối đa trong 7 ngày, nếu quá hạn sẽ bị phạt tiền 5.000 đồng/ngày. Nếu sách bị 
mất thì độc giả đó sẽ bị phạt số tiền tương ứng 200% giá sách. 
Chương trình có các chức năng sau: 
1. Quản lí độc giả 
    1. Xem danh sách độc giả trong thư viện 
    2. Thêm độc giả 
    3. Chỉnh sửa thông tin một độc giả 
    4. Xóa thông tin một độc giả 
    5. Tìm kiếm độc giả theo CMND 
    6. Tìm kiếm sách theo họ tên 
2. Quản lí sách 
   1. Xem danh sách các sách trong thư viện 
   2. Thêm sách 
   3. Chỉnh sửa thông tin một quyển sách 
   4. Xóa thông tin sách 
   5. Tìm kiếm sách theo ISBN 
   6. Tìm kiếm sách theo tên sách     
3. Lập phiếu mượn sách 
4. Lập phiếu trả sách 
5. Các thống kê cơ bản
    1. Thống kê số lượng sách trong thư viện 
    2. Thống kê số lượng sách theo thể loại 
    3. Thống kê số lượng độc giả 
    4. Thống kê số lượng độc giả theo giới tính 
    5. Thống kê số sách đang được mượn 
    6. Thống kê danh sách độc giả bị trễ hạn
