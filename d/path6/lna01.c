// Room: /d/path6/lna01.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ�������Ͽ�");
	set("long", @LONG
���������ظ�ԭɽ�������Ͽڣ�������ǻ�������ˡ�����
��ȥ�����д����ɽ�������۵ס��������ϡ����������������
�̲�ס���ﷺ������ԥ����֪���Ƿ�þٲ���ǰ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/chengdu_w/ccg35",
  "north" : __DIR__"lna00/entry",
]));
        set("outdoors", "path6");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
