#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	p->pNext = l->header;   // 今の先頭を p->next に
	l->header = p;          // p を新しい先頭おく
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (!p) return;                // p が NULL なら何もしない
	node* target = p->pNext;       // 削除するノード

	if (!target) return;           // 次がないなら何もしない

	p->pNext = target->pNext;      // 削除ノードをリストから外す
	//ただしメモリ解放はしない（仕様に合わせている）
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}
