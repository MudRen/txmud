// Room: huashan yujiantai by pian
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����̨");
	set("long", @LONG
������һ��ʮ���ɼ��������Ѿ͵ĸ�̨����ɽ�ɵ���ƽʱ��
������������̨�������ǻ�ɽ�ɵĴ���(qi)�����ߵ�·��������
ͨ��Ժ�����ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "westdown" : __DIR__"huacong2",
  "eastdown" : __DIR__"huacong1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "yingbi" : HIR"    һ�����������ƶˣ��������������ơ�
  
    ������һ���֣�������������Ϊ���棬��Ϊ������
"NOR,
]));
	set("no_clean_up", 0);
	set("outdoors", "huashan_p");

	setup();
	replace_program(ROOM);
}