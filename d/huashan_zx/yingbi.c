// Room: longbi1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����Ӱ��");
	set("long", @LONG
ӭ��һ�µ������Ƶ�Ӱ��ǽ(yingbi)��Ӱ�ڲ���̫�ߣ�����
��վ�������������ٸߣ�Ҳֻ�ܿ���Ժ���﷿�ݵĶ��Ӷ��ӡ�
�����Ǵ��Ŷ������������Ҳ˿��������Ժ������������
    ����һƬ�Ϻ죬����������һ��ǿ�Ҷ����ȵ�������
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"doorgd",
  "west" : __DIR__"guodaow",
  "east" : __DIR__"guodaoe",
]));

	set("item_desc", ([ /* sizeof() == 1 */
  "yingbi" : HIR"    һ�����������ƶˣ��������������ơ�
  
    ������һ���֣�������������Ϊ���棬��Ϊ������
"NOR,
]));

	set("valid_startroom", 1);
	set("outdoors", "huashan_zx");
	setup();
	load_board("board_huashan");
}
