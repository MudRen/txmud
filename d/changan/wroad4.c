// wroad4  �������

inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
�����ǳ����ǵ��������������ֱͨ�ʳǵ����ţ������ʹ�
��������ˮ��ˮ����ÿ���гɳ���Ȫˮ�������˽��ʹ�����ʱ��
Ѻˮ�Ĺ�Ա���ߺ��š��رܡ�����������̩·�������������·
�ڣ����߲�Զ���ǳ����ǵ����š�
LONG
        );

	set("exits", ([
                "north"            : __DIR__"wroad3",
                "west"             : __DIR__"wdoor",
                "east"             : __DIR__"wroad9",
                "south"            : __DIR__"wroad5",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/shusheng" : 1,
]));

        setup();
	replace_program(ROOM);
}