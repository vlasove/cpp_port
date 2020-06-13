#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        if (tasks_log.count(person) == 0) {
            return {};
        }
        else {
            return tasks_log.at(person);
        }
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++tasks_log[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        if (tasks_log.count(person) == 0) {
            return make_tuple(TasksInfo{}, TasksInfo{});
        } 
        if (task_count > TasksCounter(person)) {
            task_count = TasksCounter(person);
        }
        auto status = TaskStatus::NEW;
        TasksInfo updated_tasks, untouched_tasks;

        for (int i = 0; i < task_count; i++) {
            if (tasks_log[person][status] == 0) {
                auto new_status = static_cast<TaskStatus>(static_cast<int>(status) + 1);
                tasks_log[person].erase(status);
                status = new_status;
            }

            --tasks_log[person][status];
            ++tasks_log[person][static_cast<TaskStatus>(static_cast<int>(status) + 1)];
            ++updated_tasks[static_cast<TaskStatus>(static_cast<int>(status) + 1)];
        }

        if (tasks_log[person].count(TaskStatus::NEW) != 0) {
            untouched_tasks[TaskStatus::NEW] == tasks_log[person][TaskStatus::NEW];
        }


        return make_tuple(updated_tasks, untouched_tasks);
            
    }

private:
    int TasksCounter(const string& person) {
        int result = 0;
        for (const auto& t : tasks_log.at(person)) {
            result += t.second;
        }
        return result;
    }
    map<string, TasksInfo> tasks_log;
};



// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
