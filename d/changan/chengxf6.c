// Room: chengxf6.c   ����

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����ǳ���ة�ฮ��������һ��������ӳ����������һ����
�͵��������ּ����ɷ��衣����һ��ĵ�������磬������������
̩���Ĵ�ƿ��ʹ�����Եķǳ������š�������������ǰԺ����
���Ǻ����������ǳ������������鷿��
LONG
	);

        set("exits", ([
                 "south" : __DIR__"chengxf1",
                 "north" : __DIR__"chengxf9",
                 "east" : __DIR__"chengxf7",
                 "west" : __DIR__"chengxf8",
]));
        set("item_desc", ([ /* sizeof() == 2 */
		"����": "��������\n",
        ]));

	set("objects",([
	__DIR__"npc/chengxiang" : 1,
]));

        setup();
	replace_program(ROOM);
}