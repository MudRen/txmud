// /d/changan/duchang1.c

inherit ROOM;

void create()
{
        set("short", "�ķ���Ժ");
        set("long", @LONG
�������ȫ�������ĳ����ķ���Ժ���ķ��������˷��Ľ�
���������ӡ�Ԫ��������������ײ��ʹ��Ҳ����ѪҺ����������
���ﵽ�Ե��ر�İ�����һ��Ŀ������ˣ��ͻ����������һ��
���ʵĿ���������һ�����顣
LONG
        );
        
        set("exits", ([
                "east" : __DIR__"duchang",
	]));

        setup();
}


int init()
{
        add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
         object me;
         me = this_player();
         if( !arg || arg != "didao")
         return notify_fail("ʲô��\n");
         if ( arg =="didao")
        {
         write("�㲦��ǽ�ǵĲݴԣ�ͻȻ������һ���ص�����Ѹ�ٵ����˽�ȥ��\n");
         message("vision",
         me->name() + "���㲻ע�⣬ͻȻ����ǽ�ǵĲݴ��У���ʧ�����ˣ�\n",
                     environment(me), ({me}) );
         me->move("/d/houjizhen/shangang");
         message("vision",
                  me->name() + "ͻȻ�����������ǰ���·����Ѿ�������þ��ˣ�\n",
                             environment(me), ({me}) );
          }
          return 1;

}