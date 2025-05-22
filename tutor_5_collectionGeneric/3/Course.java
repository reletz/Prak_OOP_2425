import java.util.HashSet;

public class Course {
    private String courseID;
    private String courseName;
    private HashSet<String> enrolledStudents;

    // Ctor untuk membuat objek Course dengan ID dan nama
    // Note: jangan lupa untuk menginisialisasi enrolledStudents
    public Course(String courseID, String courseName) {
        enrolledStudents = new HashSet<>();
        this.courseID = courseID;
        this.courseName = courseName;
    }

    // Method untuk menambahkan student ke dalam enrolledStudents
    public void addStudent(String studentID) {
        enrolledStudents.add(studentID);
    }

    // Getter untuk mendapatkan student yang terdaftar di course
    public HashSet<String> getEnrolledStudents() {
        return enrolledStudents;
    }

    // Getter untuk mendapatkan courseID
    public String getCourseID() {
        return this.courseID;
    }

    // Getter untuk mendapatkan nama course
    public String getCourseName() {
        return this.courseName;
    }
}
