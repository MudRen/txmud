// Room: /d/path5/kch31.c

inherit ROOM;

void create()
{
	set("short", "���ɽ����");
	set("long", @LONG
��������ɽ�����ɽ���塣������ɽ���䣬��ᶶ��ơ�ɽ��
��ˮ�������������������塣���ǵ������У�����������ҩ����
һƬ���Ƹ�����Ū�����ϰ���ʪ¶¶�ģ�����������������Ĩ
��Ĩ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch30",
  "southdown" : __DIR__"kch32",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
