// Room: /d/shaolin/yongdao4.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�����������µ�һ����ʯ������Ϊ�ں�Ժ�����ǵش��صأ�
ֻ���������ݸߵ�ɮ�˲����������������������������
�У���������������Ȼ���������ҵľ��硣���������Ƿ��ɵ�
��������������ʯ�������������������ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"lroad4",
  "northeast" : __DIR__"rroad4",
  "south" : __DIR__"yongdao3",
  "north" : __DIR__"fangzhang1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
