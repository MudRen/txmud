// shulin.c ���� 

inherit ROOM;
void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
һ����С����ʯ�̳ɵ�С·���ּ����죬��Ҷ��΢�紵����
��ˢˢ�����죬ż�������ּ�������ͷ���ɹ���
LONG
        );
       set("exits", ([
                "north"             : __DIR__"shilu4",
                "east"              : __DIR__"shulin2",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
