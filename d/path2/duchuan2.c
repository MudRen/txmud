// Room: /d/path2/duchuan2.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "С�ɴ�");
	set("long", @LONG
����һ����С�Ķɴ���ľͷ�ṹ�����������������˵�����
��վ������ңң�λΣ����˸о��ܲ���ʵ��
LONG
	);

	set(SAFE_ENV,1);
	set("no_clean_up",1);

	set_boat_master(__DIR__"npc/chuanjia");
	set_boat_bank1(__DIR__"hou_t10");
	set_boat_bank2(__DIR__"hou_t11");
	set_bank1_desc("�ƺӶ���");
	set_bank2_desc("�ƺ�����");
	set_cross_msg("���ƺ�");

	setup();
}
