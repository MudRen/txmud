// /d/changan/eroad6  ���½�

inherit ROOM;

void create()
{
        set("short", "���½�");
        set("long", @LONG
���ǳ����ǵĶ���֣����ڿ��������ǵĶ����ǣ��������
��Ҳ�����������������������������˺��٣���������Ҳ�͸�
���ˣ�ֻ���ڲ�Զ����һ�������̡���������������������ʹ��
����һ���������ϱߺͱ����ǳ����Ķ���֣�������һ������
���ӡ�
LONG
        );
       set("exits", ([
                "north"           : __DIR__"eroad7",
                "west"            : __DIR__"ironroom",
                "south"           : __DIR__"eroad5",
]) );
        set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

        setup();
	replace_program(ROOM);
}
