# Philosophers

This project is a simulation of the dining philosophers problem.

## Main Branch

The `main` branch of this project uses mutexes to handle the forks and other shared resources. This is a classic solution to the dining philosophers problem, but it can be prone to deadlocks if not implemented carefully.

## Bonus Branch

The `bonus` branch of this project uses semaphores instead of mutexes. This approach is more robust and less prone to deadlocks. The main differences are:

*   **Synchronization:** Instead of using `pthread_mutex_t`, the `bonus` branch uses `sem_t` for synchronization.
*   **Fork Handling:** The `bonus` branch uses a single semaphore to represent all the forks, while the `main` branch uses a separate mutex for each fork.
*   **Resource Management:** The `bonus` branch uses `sem_open`, `sem_close`, and `sem_unlink` to manage the semaphores, while the `main` branch uses `pthread_mutex_init` and `pthread_mutex_destroy`.

Overall, the `bonus` branch is a more advanced and robust solution to the dining philosophers problem.