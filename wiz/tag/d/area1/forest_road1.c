///////////////////////////////////////////////////
//���ּ�С·�� [/d/path3/k_h22]
//�µ�����area1
//forest_road1.c

inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
�㴩����Ũ�ܵ������У�����Χ�������鶼��������
�����Էֱ����ںη������������ƺ�����һ�����ӣ�����
���Ծ���Ҫ���ı��߲źá�ʱ��ʱ�㻹���������д�����
��ֵ�������
LONG
        );
        set("exits", ([
        "west"        :  "/d/path3/k_h22",
        "east"        :  __DIR__"forest_road2",
        "north"       :  __DIR__"forest_road1",
        "south"       :  __DIR__"forest_road1",
        ]));
        set("outdoors", "area1");
        
        setup();

        replace_program(ROOM);
}
///////////////////////////////////////////////////
