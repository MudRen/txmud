// /d/changan/eroad7  ���½�

inherit ROOM;

void create()
{
        set("short", "���½�");
        set("long", @LONG
���ǳ����ǵĶ���֣����ڿ��������ǵĶ����ǣ��������
��Ҳ�����������������������������˺��٣���������Ҳ�͸�
���ˣ����Ƕ����һ��С�ƹݲ�ʱ������������Ц������������
ƽ������ǵľۼ��أ�Ҫ��̽ʲô��Ϣ���Ǹ��õط���
LONG
        );
       set("exits", ([
		"east"		  : __DIR__"jiuguan",
                "north"           : __DIR__"eroad8",
                "south"           : __DIR__"eroad6",
]) );
        set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 1,
]));
        setup();
	replace_program(ROOM);
}
