// shilu.c ʯ��· 

inherit ROOM;
void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
һ������ʯ��·���ֵ����Ե�С���������߹�������ʧʱ
��������˽������������ֵ��Ķ�����һ�ұ����̣�����������
�������봨��ݣ���˵�������ܽ�ͷ�书�ܺá�
LONG
        );
       set("exits", ([
                "north"             : __DIR__"zhenkou",
                "south"             : __DIR__"shilu2",
                "east"              : __DIR__"bingqi",
                "west"              : __DIR__"wuguan",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
