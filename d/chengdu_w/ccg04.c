// Room: /d/path5/ccg04.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��·");
	set("long", @LONG
������һ������ʯ�̳ɵĴ�·�ϣ�·��ʮ��ƽ����·��һ��
��ׯ�ڵأ���һ�����ǸߵͲ����ɽ�룬����һЩ������ɢ�ķ�
�������ǵ���ũ���ס����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg05",
  "east" : __DIR__"ccg03",
]));
        set("outdoors", "chengdu_w");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
