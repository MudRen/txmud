// Room: /d/changan/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС�ĵ��̣�����ĳ����൱�ļ򵥣�������һ��
��̨����̨�߷���һ�����ӡ���̨��������ʽ������С��Ʒ��
������һ�����ӻ��ĵ��̡�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sroad6",
]));

	set("objects",([
	__DIR__"npc/liujinfeng" : 1,
]));

	setup();
}