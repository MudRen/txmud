int valid_leave(object me, string dir)
{
  object ob;
  if(me->query_temp("taxue/job_name") && objectp(present("yeshou", environment(me))))
               return notify_fail("��Ȼ��������������ǰ���ȵ�������������ҹ�������\n");

  if(me->query_temp("heiyi/heiyi_rob") && objectp(ob = present("hubiao biaoshi", environment(me)))
     && ob->query("target") == me)
               return notify_fail("������ʦ������ס���ȥ·�����������������ˣ�\n");  

  if(me->query_temp("heiyi/heiyi_rob") && objectp(present("biao dui", environment(me))))
               return notify_fail("�̶��������أ�����(qiang)����\n");  

      return ::valid_leave(me, dir);
} 