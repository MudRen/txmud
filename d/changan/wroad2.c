// wroad2  ��̩·

inherit ROOM;
void create()
{
        set("short", "��̩·");
        set("long", @LONG
�����ǳ���������ֱ��ߣ��ǳ���������ĵض�֮һ����
�������̺��ܵ궼�ڸ�����ƽ������������������������ϣ���
��ҲҪ�ƻ�ͨ��ֱ����ҹ���ݡ���ʱ���гֵ������־���������
���������ػص�Ѳ�ߡ������Ľֵ����ϱ����������죬������һ
��ר�������ֻ����̵ꡣ
LONG
        );

       set("exits", ([
                "north"            : __DIR__"wroad1",
                "west"             : __DIR__"zhubao_room",
                "south"            : __DIR__"wroad3",
]) );

	set("outdoors","changan");
	set("objects",([
	__DIR__"npc/beggar" : 1,
]));
        setup();
	replace_program(ROOM);
}