#pragma once

class TaskManager;
enum {
	eType_Enemy,
	eType_Player,
	eType_Star,
	eType_Timer,
	eType_Field,
	eType_Score,
	eType_Constellation,
	eType_Title,
	eType_Game,
	eType_Result,
	eType_Effect,
	eType_Load
};
//タスクの優先度の種類
enum class ETaskPrio
{
	Title,
	Result,
	EnemyManager,
	Game,
	Field, //フィールド
	Nomal,
	Shadow, //影
	Object, //オブジェクト（プレイヤーとか敵とか）
	UI,
	
	Effect,
};
class Task
{
	friend TaskManager;

public:
	//コンストラクタ
	Task(int prio,int sortOrder,int type);
	//デストラクタ
	virtual ~Task();

	//更新
	virtual void Update();
	//描画
	virtual void Render();

	virtual void Collision(Task*b);
	

	
	//有効フラグを設定
	void SetEnable(bool enable);
	//有効フラグを取得
	bool IsEnable() const;

	//表示フラグを設定
	void SetShow(bool show);
	//表示フラグを取得
	bool IsShow() const;

	//タスクを削除
	void Kill();
	//削除フラグが立っているか
	bool IsKill() const;

	//優先度を設定
	void SetPriority(int prio);
	//優先度を取得
	int GetPriority() const;

	//優先度内の順番を設定
	void SetSortOrder(int order);
	//優先度内の順番を取得
	int GetSortOrder() const;
	
private:
	bool m_isEnable; //有効フラグ
	bool m_isShow; //表示フラグ
	bool m_isKill; //削除フラグ
	int m_prio; //優先度
	int m_sortOrder; //同じ優先度内での順番
public:
	int m_type;
	
};