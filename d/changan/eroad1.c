// /d/changan/eroad1  ���½�

inherit ROOM;

void create()
{
        set("short", "���½�");
        set("long", @LONG
�����Ƕ���ֵ��ϱߣ�·���ߵ������˺����˲���ܶ࣬��
�治Զ��һ������������һЩ���㻹Ը��������Ů������·����
��Ȼ���в�����ٹ��˺����ǵ���Ů��Ҳ��һЩ�нŵĺ�������
������ի��������������ؤ�������������Ҳ���������һ��
���ۡ�
LONG
        );
       set("exits", ([
                "west"           : __DIR__"badroom",
                "south"           : __DIR__"sroad8",
                "north"           : __DIR__"eroad2", ]) );
       set("outdoors","changan");

        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

        setup();
	replace_program(ROOM);
}
