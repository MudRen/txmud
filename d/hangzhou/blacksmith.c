// Room: /d/hangzhou/blacksmith.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�߽��ţ�һ����������������㲻�ɵõ�����������һ��
���δ󺺾���������վ�ڻ�¯�ԣ�ר����־�Ĵ�����ʲô��˿
��û��ע�⵽��ĵ������ű�����һ����Ƥ��(ban)��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongning",
]));


        set("item_desc", ([ /* sizeof() == 2 */
	"ban" :  "
�չ���������
����(fix)����
��Կ��(pei key)\n
",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
