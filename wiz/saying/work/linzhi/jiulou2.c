//jiulou2.c ����������㡣

inherit ROOM;

void create()
{
        set("short", "����¥����");
        set("long", @LONG
���������������¥�Ķ�¥��һ����������е�λ���˲�����
���Ͳ͵ĵط�������������徻���࣬���̵�С��Ҳ�ܿ��ˣ�����
�������˵Ļ�����������͡�
LONG
        );

        set("night_long",@LONG
���������������¥�Ķ�¥�������Ѿ������ϣ���¥�Ѿ���
���ˣ��ƹ�����ڹ�̨����������
LONG
);
        set("no_clean_up", 0);
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
	"down" : __DIR__"jiulou",
]));
        set("objects",([
        __DIR__"npc/jiulou_boss" : 1,
]));
        set("NORIDE","С��¥��̫խ������������������ϲ�ȥ��");
        setup();
        replace_program(ROOM);
}
