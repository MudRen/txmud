// iron_mine.c
// ����

#include <mine_def.h>

inherit MINE_FIELD;

void create()
{
	set_maze_long(10);				// �������߳�
	set_mine_room(__DIR__"mine_room");		// �п󷿼�
	set_no_mine_room(__DIR__"no_mine_room");	// �޿󷿼�
	set_contain_quantity(10000000);			// ��λ(��),100���
	set_contain_persent(15);			// �̲ر���
	set_reset_time_sect(20);			// �����ڣ�Game�꣩
	set_mine_class(IRON_MINE);			// ����
	set_entry_dir("west");				// ��ڷ���
	set_link_entry_dir("west");			// ��ں���������ӷ���
	set_link_entry_room(__DIR__"ftn13");		// ������������򵵰����ļ���
}
