// Room: /u/w/wangs/b/kai170.c

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long", @LONG
����һ����ͨ���񷿣������ķ����ڿ��⸮�ı�Ե�����ܹ�
��������������˴����һλʯ����Ժ���������ﵽ����������
ʯ��ʯ���͸��ֹ��ߡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai163",
]));

	set("objects",([
	__DIR__"npc/shijiang" : 1,
]));

	setup();
	replace_program(ROOM);
}
