// Room: /u/w/wangs/b/kai104.c

inherit ROOM;

void create()
{
	set("short", "Ƥ����");
	set("long", @LONG
��ɫ��쵸��ֻ�����¡�������ñ������Ƥ������ص�����
����Ļ����ϣ���ЩƤ���������Զ����ຮ֮�أ������Ǿ��Ե�
�ϳˣ���������̫���ˣ�һ��ƽ������Ƥ�����Ҫ������ʮ����
�ӣ�Ѱ���İ���������Ե�ʽ��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai103",
]));
        set("objects",([
        __DIR__"npc/gaolaoban" : 1,
]));

	setup();
	replace_program(ROOM);
}
