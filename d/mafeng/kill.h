int valid_leave(object me, string dir)
{
  if(objectp(present("ma yigun", environment(me))))
               return notify_fail("��һ��������������ǰ���ȵ��������ܣ����ҹ�������\n");

  if(objectp(present("lou lou", environment(me))))
//     && ob->query("target") == me
               return notify_fail("��������ס���ȥ·�����������������ˣ�\n");  

      return ::valid_leave(me, dir);
} 