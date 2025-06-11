import java.util.List;
import java.util.ArrayList;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        tasks = new ArrayList<Task>();
    };

    public void addTask(Task newTask){
        tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            //TODO: Fill with the operation that will process the tasks. Hint: the operation is exactly
            // the same with the operation that exist on Worker.java with a little improvement;)
            for (Task task: tasks){
                Thread.sleep(task.getTime());
                synchronized (task) {
                    task.setStatus("done");
                    task.notify();
                }
            }
        } catch (InterruptedException e) {
            System.out.println("Worker Error!");
        }
    }

}
