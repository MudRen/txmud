// /d/changan/nroad5  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵı���֣���ֵ�������Ⱥ����������������
��������ĵض��ˡ��ϵĳ����ǵİ�������˵��������Ҫ����
�ˣ����ֶ����ս�����������һ�ҶĹݣ���ʱ����ߺ������Ľ�
������
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad6",
                "south"           : __DIR__"duchang",
                "east"            : __DIR__"nroad4",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/dutu" : 1,
]));

        setup();
	replace_program(ROOM);
}
