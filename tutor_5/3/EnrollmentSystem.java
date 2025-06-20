import java.util.HashMap;
import java.util.HashSet;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        this.students = new HashMap<>();
        this.courses = new HashMap<>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        Student a = new Student(studentID, name);
        this.students.put(studentID, a);
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course a = new Course(courseID, courseName);
        this.courses.put(courseID, a);
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        try {
            Student a = students.get(studentID);
            Course b = courses.get(courseID);
            b.addStudent(studentID);
            a.enrollCourse(courseID);
            students.replace(studentID, a);
            courses.replace(courseID, b);
        } catch (Exception e) {
            System.out.println("Student atau course tidak ditemukan!");
        }
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
        Student s = students.get(studentID);
        if (s == null) {
            System.out.println("Student tidak ditemukan!");
            return;
        }
        HashSet<String> enrolled = s.getEnrolledCourses();
        System.out.println("Student " + s.getName() + " terdaftar di " + enrolled.size() + " course:");
        for (String cid : enrolled) {
            Course c = courses.get(cid);
            System.out.println(cid + " " + (c != null ? c.getCourseName() : ""));
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
        Course c = courses.get(courseID);
        if (c == null) {
            System.out.println("Course tidak ditemukan!");
            return;
        }
        HashSet<String> enrolled = c.getEnrolledStudents();
        System.out.println("Course " + c.getCourseName() + " memiliki " + enrolled.size() + " student:");
        for (String sid : enrolled) {
            Student s = students.get(sid);
            System.out.println(sid + " " + (s != null ? s.getName() : ""));
        }
    }
}
