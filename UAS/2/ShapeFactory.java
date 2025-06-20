public class ShapeFactory {
    public Shape createShape(String shapeType) throws Exception {
        // Jika shapeType adalah null lempar exception dengan pesan "Shape type cannot be null"
        // Jika shapeType tidak sesuai dengan "CIRCLE", "RECTANGLE", atau "TRIANGLE" lempar exception dengan pesan "Unknown shape type: {shapeType}"
        if (shapeType == null || shapeType.equals("")) throw new Exception("Shape type cannot be null");
        if (!shapeType.equals("CIRCLE")
        && !shapeType.equals("RECTANGLE")
        && !shapeType.equals("TRIANGLE")) throw new Exception("Unknown shape type: " + shapeType);
        // Sesuai dengan petunjuk, kita akan membuat factory method untuk membuat objek Shape berdasarkan tipe yang diberikan.

        if (shapeType.equals("CIRCLE")) return new Circle();
        if (shapeType.equals("RECTANGLE")) return new Rectangle();
        else return new Triangle();
    }
}