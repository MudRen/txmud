// Room: chengxf3.c

inherit ROOM;

void create()
{
        set("short", "��԰");
	set("long", @LONG
�����ǳ���ة�ฮ�Ļ�԰���������Ų��ٻ����ݲݣ�һ����
������ŵ�������Ļ������˷θ��������������䣬�ϱ���
��ͩ���䣬����һ����ǧ�������ة���С�㳣��������ɡ���
��������������
LONG
	);

        set("exits", ([
  "north" : __DIR__"chengxf2",
]));
        set("outdoors","chengxf");

	set("objects",([
	__DIR__"npc/yahuan" : 1,
]));

	setup();
	replace_program(ROOM);
}