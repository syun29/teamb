#include "TaskManager.h"
#include"Task.h"
#include"ObjectBase.h"

//TaskManagerのインスタンスの静的なメンバ変数を定義
TaskManager* TaskManager::ms_instance = nullptr;

//コンストラクタ
TaskManager::TaskManager()
{

}

//デストラクタ
//デストラクタ
TaskManager::~TaskManager()
{
	//オブジェクトのリストも空にする
	m_objectList.clear();
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		//削除するタスクのアドレスをいったん記憶し、
		//リストから取り除いた後に、タスクを削除する
		Task* del = *itr;
		itr = m_taskList.erase(itr);
		delete del;
	}
}
//TaskManagerのインスタンスを取得
TaskManager* TaskManager::Instance()
{
	//インスタンスが生成されてなければ、
	//インスタンス生成後に返す
	if (ms_instance == nullptr)
	{
		ms_instance=new TaskManager();
	}
	return ms_instance;
}
//TaskManagerのインスタンスを破棄
void TaskManager::ClearInstance()
{
	//インスタンスが生成されていたら、削除する
	if (ms_instance != nullptr)
	{
		delete ms_instance;
		ms_instance = nullptr;
	}
}

//タスクリストにタスクを追加
void TaskManager::Add(Task* task, bool sort)
{
	//並び変え時の追加処理でなければ
	if (!sort)
	{
		//追加されるタスクがオブジェクトであれば、
		//オブジェクトリストにも追加
		if (task->m_prio == (int)ETaskPrio::Object)
		{
			m_objectList.push_back(task);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* curr = *itr;
		//追加するタスクの優先度の値の方が小さい場合は、
		//その位置にタスクを追加する
		if (task->m_prio < curr->m_prio)
		{
			m_taskList.insert(itr, task);
			return;
		}
		//追加するタスクと現在調べているタスクの優先度が同じ場合は、
		//m_sortOrderの順番でリストに追加する
		else if (task->m_prio == curr->m_prio)
		{
			if (task->m_sortOrder < curr->m_sortOrder)
			{
				m_taskList.insert(itr, task);
				return;
			}
		}
		++itr;
	}
	//リストの間に追加する場所が見つからなかったので、
	//リストの一番最後に追加
	m_taskList.push_back(task);
}

//タスクリストからタスクを取り除く
void TaskManager::Remove(Task* task, bool sort)
{
	//並び替え時でなければ
	if (!sort)
	{
		//オブジェクトのリストからも取り除く
		if (task->m_prio == (int)ETaskPrio::Object)
		{
			m_objectList.remove(task);
		}
	}

	m_taskList.remove(task);
}


 //削除フラグが立っているタスクを削除
 void TaskManager::DeleteKilledTasks()
 {
	 auto itr = m_taskList.begin();
	 auto end = m_taskList.end();
	 while (itr != end)
	 {
		 //削除フラグが立っていたら、削除する
		 Task* task = *itr;
		 if (task-> IsKill())
		 {
			 Task* del = *itr;
			 itr = m_taskList.erase(itr);
			 delete del;
		 }
		 //削除フラグが立っていなければ、詰美のタスクを調べる
		 else
		 {
			 ++itr;
		 }
	 }
 }

 //リストに登録されているタスクを更新
 void TaskManager::Update()
 {
	 //リストの先頭から順番に更新処理を呼び出す
	 for (Task* task : m_taskList)
	 {
		 //タスクが有効であれば、更新
		 if(task->IsEnable())
		 { 
		 task->Update();
		 }
	 }
 }

 //リストに登録されているタスクを描画
 void TaskManager::Render()
 {
	 //オブジェクトリストの中身を奥行の座標が大きい順に並べる
	 m_objectList.sort
	 (
		 [](const Task* task0, const Task* task1)
		 {
			 const ObjectBase* obj0 = dynamic_cast<const ObjectBase*>(task0);
			 const ObjectBase* obj1 = dynamic_cast<const ObjectBase*>(task1);
			 return obj0->GetPos().z < obj1->GetPos().z;
		 }
	 );

	 //並び変えたオブジェクトリストの先頭から順番に
	 //SortOrderの値を設定
	 int sortOrder = 0;
	 for (Task* obj : m_objectList)
	 {
		 obj->SetSortOrder(sortOrder);
		 sortOrder++;
	 }
	 //リストの先頭から順番に描画処理を呼び出す
	 for (Task* task : m_taskList)
	 {
		 //タスクが有効かつ、表示状態ならば、描画
		 if(task->IsEnable()&&task->IsShow())
		 { 
		 task->Render();
		 }
	 }
 }
 void TaskManager::DeleteAll()
 {
	 for (Task* task : m_taskList)
	 {
		 task->Kill();
	 }
 }

 /*void TaskManager::Collision()
 {
	 
 }*/

 /*void TaskManager::CollisionCube(Task*b1,Task*b2)
 {
	 CVector2D v = b1->m_pos - b2->m_pos;
	 float l = v.Length();
	 if (l < b1->m_rad + b2->m_rad) {
		 return true;
	 }
	 return false;
 }*/

 void TaskManager::AaBb(CVector3D max, CVector3D min, CVector3D pos, Task* b1,Task*b2)
 {
	
	 
 }

 void TaskManager::Collision()
 {
	 auto it1 = m_objectList.begin();
	 auto last = m_objectList.end();
	 while (it1 != last) {
		 auto it2 = it1;
		 it2++;
		 while (it2 != last) {
			 (*it1)->Collision(*it2);
			 (*it2)->Collision(*it1);
			 it2++;
		 }
		 it1++;
	 }
 }
