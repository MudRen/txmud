// nroad6  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵı���֣����г����ĳ��У������㳵������
���������������ｻ�׵ġ������������ܵ����������������
��ͣ���ڿ����Լ��Ļ�����Ȼ���㲻�����򣬵��ǹ���������ת
ת��Ҳ�����֡��������򶫺������ǿ����ı����������Զ����
������һ�ҵ��̡�
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad7",
		"north"           : __DIR__"hockshop",
                "east"            : __DIR__"nroad5",
]) );

	set("objects",([
	NPC_DIR"xunpu" : 1,
]));

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
