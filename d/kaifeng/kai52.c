// Room: /u/w/wangs/b/kai52.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
һ�����ֺŵ��ӻ��̡�����������Ӫ�������ڿ������һ��
�Ѿ�����һЩС�������������������ν��ף����Ǵ��װ��棬��
�����ճ�������Ҫ�Ķ���һ�������١��ټ�����������ƹ����
���������һ�򶼺ܺá�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai166",
]));
        set("objects",([
        __DIR__"npc/zhboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
