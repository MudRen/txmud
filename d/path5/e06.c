// Room: /d/path5/e06.c

inherit ROOM;

void create()
{
	set("short", "�ӱ߲ݵ�");
	set("long", @LONG
������ˮ�ӵ����������ϵ���ݵ����������ż�ֻ��������
ˮ������ǰ����ȥ����Ȼˮ��̫�ˮ��ȴ��ʵ�ܼ���Ҫ���ӿ�
��ֻ���Ҵ��Ұ�æ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"e05",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
