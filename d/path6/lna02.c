// Room: /d/path6/lna02.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ�����ȱ���");
	set("long", @LONG
���������ظ�ԭɽ�����ȱ��ڣ�������ǻ��ȳ����ˡ�����
��ȥ�����д����ɽ�������۵ס��������ϡ����������������
�̲�ס���ﷺ������ԥ����֪���Ƿ�þٲ���ǰ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lna00/exit",
]));
        set("outdoors", "path6");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
