using System;
using System.Windows.Forms;
using CiscoInit.Database;
using CiscoInit.Entities;

namespace CiscoInit
{
    public partial class CiscoForm : Form
    {
        public CiscoForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (var context = new CiscoDatabaseContext())
            {
                context.SwitchRouters.Add(new SwitchRouter());
                context.SaveChanges();
                foreach (var item in context.Interfaces)
                {
                    label1.Text += item.Id + " ";
                }
            }
        }

        private void switchRoutersBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            Validate();
            //switchRoutersBindingSource.EndEdit();
            tableAdapterManager.UpdateAll(ciscoDataSet);
        }

        private void CiscoForm_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "ciscoDataSet.SwitchRouters". При необходимости она может быть перемещена или удалена.
            this.switchRoutersTableAdapter.Fill(this.ciscoDataSet.SwitchRouters);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "ciscoDataSet.Interfaces". При необходимости она может быть перемещена или удалена.
            this.interfacesTableAdapter.Fill(this.ciscoDataSet.Interfaces);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "ciscoDataSet.SwitchRouters". При необходимости она может быть перемещена или удалена.
            //switchRoutersTableAdapter.Fill(ciscoDataSet.SwitchRouters);
        }

        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {
            /*using (var context = new CiscoDatabaseContext())
            {
                context.SwitchRouters.Add(new SwitchRouter());
                context.SaveChanges();
            }*/
            //switchRoutersTableAdapter.Fill(ciscoDataSet.SwitchRouters);
        }

        private void interfacesBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.interfacesBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.ciscoDataSet);

        }
    }
}