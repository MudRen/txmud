// Room: /d/xizang/lal01.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ��");
	set("long", @LONG
�����ڸ�ԭɽ·�ϣ�ϡ���Ŀ���ʹ���𽥸е����ʣ�������
���Ǹ�ɽ��ӳ�ˣ���ֻ�������˽Ų����ɴ����򶫾�����֥�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/linzhi/linzhiw",
  "west" : __DIR__"lal02",
]));
        set("outdoors", "path6");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
