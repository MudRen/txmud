// /d/changan/sroad1  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���ǳ����ǵ��ϴ�֣������ϴ�������Խ��ԽԶ����Ҳ��
�����ٶ��ˡ�������Զ����ղ����֣�ż������һ�������ִ߽�
���С����ߺ�������������˵���ϴ������ľ�ͷ�ˣ�������
�ϴ�֣�����ȴ����������ˡ�������һ�����䳡��
LONG
        );
       set("exits", ([
                "west"           : __DIR__"wroad8",
                "north"          : __DIR__"compare2",
                "east"           : __DIR__"sroad2", ]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
