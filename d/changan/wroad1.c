// wroad1  ��̩·

inherit ROOM;
void create()
{
        set("short", "��̩·");
        set("long", @LONG
�����ǳ���������ֱ��ߣ��ǳ���������ĵض�֮һ����
�������̺��ܵ궼�ڸ�����ƽ������������������������ϣ���
��ҲҪ�ƻ�ͨ��ֱ����ҹ���ݡ���ʱ���гֵ������־���������
���������ػص�Ѳ�ߡ��������򱱾��Ǿ�������������֣�����
�Ǳ���Ϊ��������ʳ��һ¥��������¥��
LONG
        );
       set("exits", ([
                "north"            : __DIR__"nroad8",
             "west"            : __DIR__"yiguan",
		"east"		   : __DIR__"jiulou",
                "south"            : __DIR__"wroad2", ]) );
       set("outdoors","changan");
        setup();

	replace_program(ROOM);
}