
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;



TaskStatus Next(const TaskStatus& current_status) {
    auto next = static_cast<TaskStatus>(static_cast<int>(current_status) + 1);
    return next;
}



void RemoveZero(TasksInfo& tasks) {
    vector<TaskStatus> to_delete;
    for (const auto& p : tasks) {
        if (p.second == 0) {
            to_delete.push_back(p.first);
        }
    }
    for (const auto& item : to_delete) {
        tasks.erase(item);
    }
}

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
        TasksInfo updated_tasks, untouched_tasks;

        TasksInfo& tasks = tasks_log[person];

        for (auto status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
            updated_tasks[Next(status)] = min(task_count, tasks[status]);
            task_count -= updated_tasks[Next(status)];

        }

        for (auto status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
            untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
        }

        tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];


        RemoveZero(updated_tasks);
        RemoveZero(untouched_tasks);
        RemoveZero(tasks_log.at(person));

        return { updated_tasks, untouched_tasks };
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
