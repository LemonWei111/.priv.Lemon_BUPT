�����ĵ���
cnnlagru_caption.ipynb//VGG19�����ʾ+GRUģ��ѵ���빦����֤����
train.ipynb                   //ResNet101�ֲ���ʾ+LSTM+ע��������ģ��ѵ������
caption.ipynb              //ResNet101�ֲ���ʾ+LSTM+ע��������ģ�͹�����֤����

˵��������������
--.ipynb_checkpoints   //JupterNotebook�����Զ����ɵ�.ipynb�ļ����ļ�

--images
    --example.jpg         //ϵͳʵʱ����洢ͼ��
    --start.jpg               //ϵͳ��ҳ��չʾͼ��

#��ƽ̨�ϴ��ļ���С���ƣ�ȡ������skip�������ϴ�
##########################skip###########################
--model                     //VGG19�����ʾ+GRUģ��
    --MYMODL
        --last.ckpt         //���һ��ѵ����ģ����ز���state = {
                                    //'epoch': epoch,
                                    //'step': i,
                                    //'model': model,
                                    //'optimizer': optimizer
                                //}
        --mymodl.pth   //ϵͳʹ�õ�ģ�Ͳ���
##########################skip###########################

--api.py                    //����api

--checkpoint1_DeepFashion_MultiModal.pth.tar
                               //ResNet101�ֲ���ʾ+LSTM+ע��������ģ�ͼ���

--datasets.py           //����getdata.py��С�仯�����ݼ�����

--evaluate.py           //ʵ��bleu_4��rouge_l����ָ�꣬ʵ������ת��Ϊ�ı�����

--getdata.py            //���ݼ����أ�ѵ��+����/ѵ��+��֤+���ԣ���ͬʱ�ṩ�ʵ����ɵ�����Ԥ������

--log.txt                  //VGG19�����ʾ+GRUģ�����һ��ѵ����¼

--menu.jpg             //ϵͳ��ʼͼƬ

--menu.py              //ϵͳ��ҳ��

--modelcr.py          //VGG19�����ʾ+GRUģ�Ͷ���

--models.py           //ResNet101�ֲ���ʾ+LSTM+ע��������ģ�Ͷ���

--pages.py             //ϵͳ��ʼע���¼ҳ��

--solver.py             //ResNet101�ֲ���ʾ+LSTM+ע��������ģ�͵�ѵ������֤����

--upload.py           //ͼ����ӻ�����ʾ��

--utils.py               //�ı���������ӻ�����