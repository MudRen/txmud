///////////////////////////////////////////////////
//�µ�����area1
//forest_road5.c

inherit ROOM;

void create()
{
        set("short", "ɭ�ֱ�Ե");
        set("long", @LONG
��������ɭ���뿪���صĽ��紦�������߱��ܽ���
ɭ�֡�����������С·����֪ͨ��η��������п�ߵء�
LONG
        );
        set("exits", ([
        "west"        :  __DIR__"forest_road4",
        "northeast"   :  __DIR__"plain_road1",
        "northup"     :  __DIR__"mountain_road1",
        ]));
        set("outdoors", "area1");
        
        setup();

        replace_program(ROOM);
}
///////////////////////////////////////////////////
