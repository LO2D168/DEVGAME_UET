# Typing Attack - Make By SDL2 C++
<p align="center">
 <strong>Author</strong>: Đào Văn Đức
</p>
<p align="center">
 <strong> Student ID </strong>: 24021409
</p>

- [A. Introduction](#A-introduction)
  * [Setup Enviroment](#1-Setup-Enviroment)
  * [Tutorial](#2-Tutorial)
- [B. Sources](#B-sources)
- [C. Conclusion](#C-conclusion)

# A. Introduction
Đây là game được em viết trong khoảng **5 tuần** và cũng là game đầu tiên mà em viết. Game sẽ giúp mọi người **luyện khả năng gõ phim**, hy vọng mọi người tận hưởng nó !!!

Các thư viện đi kèm: **bits**, **SDL2**, **SDL2-image**, **SDL2-ttf** và **SDL2-mixer**.

# 1. Setup Enviroment
- Chạy file **main.exe** để chơi hoặc
- Sử dụng [mingw64](https://www.mingw-w64.org/) và các thư viện [SDL2](https://www.libsdl.org/) đi kèm để build file **main.cpp**. Chạy file vừa build được để chơi. 
- **Khuyến cáo sử dụng CLion hoặc các IDE có khả năng đọc file cmake.**
# 2. Tutorial
Sử dụng 4 phím mũi tên trên bàn phím để di chuyển né các vật thể như **cầu lửa vũ trụ**, **phi thuyền địch** cùng với **đạn laser** từ địch. 

Gõ phím chính xác các từ xuất hiện ở **góc trái màn hình** để bắn đạn. Đạn sẽ được định vị hướng đến **vị trí tàu địch gần nhất** và có sức mạnh **giảm dần**.
Theo thời gian độ dài cũng như phức tạp của **từ** càng khó.

Điểm sẽ được tính bằng **số phi thuyền của địch bị bắn hạ**.

Nhân vật chính có **5 mạng** và số mạng giảm đi sau mỗi lần va chạm với các vật thể kể trên.

# B. Sources
Game được em tự viết hoàn toàn với một số tham khảo từ:
- **Các dòng game Typing**.
- Cách làm việc với SDL từ **LazyFoo**.
- Một số thuật toán xử lý va chạm từ Internet.
- Nguồn ảnh phong phú và chất lượng của chatGPT.
- Âm thanh lấy từ [FreeSound](https://freesound.org/).
- Font chữ được lấy từ nguồn Internet.
# C. Conclusion
Qua quá trình làm game em được học được cách làm quen với 1 ngôn ngữ, thư viện và rèn luyện cải thiện cách thức tổ chức chương trình. Đặc biệt là việc sử dụng AI vào sinh ảnh giúp em giảm được đáng kể thời gian làm game.
Sau cùng em tự đánh giá game em làm là 1 game hay và có ý nghĩa trong việc học tiếng Anh cũng như kỹ năng gõ phím đồng thời là game đáp ứng được tất cả các tiêu chí trong checklist nên em tự đánh giá game em xứng đáng được **10 điểm**, nhưng nếu điểm số thấp hơn thì em cũng chấp nhận.
